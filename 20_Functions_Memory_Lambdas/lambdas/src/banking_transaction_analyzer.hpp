#ifndef BANKING_ANALYZER
#define BANKING_ANALYZER

#include <string>
#include <vector>

// ==========================================
// Part 1: The Generic Processor
// ==========================================

// 1. The Data
struct Transaction
{
  int id;
  double amount;
  std::string type; // "Deposit" or "Withdrawal"
};

// 2. The Engine
#define USE_STD_FUNCTION 0
#if USE_STD_FUNCTION

#include <functional>

void process_transactions(
  const std::vector<std::unique_ptr<Transaction>>& transactions,
  const std::function<bool(const std::unique_ptr<Transaction>&)>& predicate,
  const std::function<void(const std::unique_ptr<Transaction>&)>& consumer)
{
  for (const auto& t : transactions){
    if (predicate(t)) {
      consumer(t);
    }
  }
}

#else
// We use templates here so the compiler can inline the lambdas.
// This matches the flexible nature required by the startup scenario.
template <typename Predicate, typename Consumer>
void process_transactions(
  const std::vector<std::unique_ptr<Transaction>>& transactions,
  Predicate&& predicate,
  Consumer&& consumer)
{
  for (const auto& t : transactions){
    if (predicate(t)) {
      consumer(t);
    }
  }
}
#endif


#endif // BANKING_ANALYZER