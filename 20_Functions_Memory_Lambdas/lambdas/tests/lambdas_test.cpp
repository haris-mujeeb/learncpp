#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include "banking_transaction_analyzer.hpp"


// ==========================================
// Part 2: Captures & State (The Application)
// ==========================================-
class BankingAppTest : public ::testing::Test {
 protected:
  std::vector<std::unique_ptr<Transaction>> transactions;

  void SetUp() override {
    transactions.reserve(5);
    transactions.emplace_back(std::make_unique<Transaction>(Transaction{1, 1500.0, "Withdrawal"}));
    transactions.emplace_back(std::make_unique<Transaction>(Transaction{2, 500.0, "Withdrawal"}));
    transactions.emplace_back(std::make_unique<Transaction>(Transaction{3, 2000.0, "Deposit"}));
    transactions.emplace_back(std::make_unique<Transaction>(Transaction{4, 1200.0, "Withdrawal"}));
    transactions.emplace_back(std::make_unique<Transaction>(Transaction{5, 300.0, "Withdrawal"}));
    transactions.emplace_back(std::make_unique<Transaction>(Transaction{6, 800.0, "Deposit"}));
  }

  void TearDown() override {}
};

TEST_F(BankingAppTest, InitlizationTest) {
  for (size_t i = 0; i < transactions.size(); i++) {
    ASSERT_EQ(transactions[i]->id, i + 1);
  }
}

TEST_F(BankingAppTest, DynamicFilteringTest) {
  const double THRESHOLD = 1000.0;

  auto predicate_lamda = [THRESHOLD](const std::unique_ptr<Transaction>& t) -> bool {
    return t->type == "Withdrawal" && t->amount > THRESHOLD;
  };
  
  double total_processed = 0.0;
  auto consumer_lamda = [&total_processed](const std::unique_ptr<Transaction>& t) {
    total_processed += t->amount;
  };

  process_transactions(transactions, predicate_lamda, consumer_lamda);

  ASSERT_GT(total_processed, 0.0);
  EXPECT_EQ(total_processed, 2700.0);
}

// ==========================================
// Part 3: The Lambda Factory (Higher-Order Function)
// ==========================================

// Returns a lambda that "remembers" (captures) the specific rate provided.
auto make_currency_converter(double rate) {
  return [rate](double amount){ return amount * rate; };
}

TEST_F(BankingAppTest, LambdaFactoryTest) {
  const double THRESHOLD = 1000.0;

  auto predicate_lamda = [THRESHOLD](const std::unique_ptr<Transaction>& t) -> bool {
    return t->type == "Withdrawal" && t->amount > THRESHOLD;
  };
  
  double total_processed = 0.0;
  auto consumer_lamda = [&total_processed](const std::unique_ptr<Transaction>& t) {
    total_processed += t->amount;
  };

  process_transactions(transactions, predicate_lamda, consumer_lamda);
  
  double rate = 0.85;
  auto usd_to_eur = make_currency_converter(rate);
  double total_eur = usd_to_eur(total_processed);
  
  EXPECT_DOUBLE_EQ(total_eur, total_processed * rate);
}