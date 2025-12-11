#include <gtest/gtest.h>
#include <vector>
#include "pointer_sorter.hpp"


// --- Test Fixture ---
class PointerSorterTest : public ::testing::Test {
protected:
  std::vector<const Widget*> CreateWidgetPointers(const std::vector<int>& ids) {
    test_widgets_.clear();
    test_widgets_.reserve(ids.size()); // Pre-allocate memory to prevent reallocation
    std::vector<const Widget*> ptrs;
    
    for (int id : ids) {
      test_widgets_.push_back({id});
      ptrs.push_back(&test_widgets_.back());
    }
    return ptrs;
  }

  void VerifySortedIDs(
    const std::vector<const Widget*>& ptrs, 
    const std::vector<int>& expected_ids) 
  {
    ASSERT_EQ(ptrs.size(), expected_ids.size());
    for (size_t i = 0; i < ptrs.size(); i++) {
      ASSERT_NE(ptrs[i], nullptr) << "Found null pointer at index " << i;
      EXPECT_EQ(ptrs[i]->id, expected_ids[i]) << "Mismatch at index " << i;
    }
  }
private:
  std::vector<Widget> test_widgets_;
};

TEST_F(PointerSorterTest, HandlesEmptyArray) {
  EXPECT_NO_THROW(sort_widgets_by_id(nullptr, 0));
}

TEST_F(PointerSorterTest, SortsThreeUnorderedElements) {
  constexpr int size = 3;
  auto ptrs = CreateWidgetPointers({2, 3, 1});

  sort_widgets_by_id(ptrs.data(), size);

  VerifySortedIDs(ptrs, {1, 2, 3});
}

TEST_F(PointerSorterTest, SortsAlreadySortedArray) {
  auto ptrs = CreateWidgetPointers({10, 20, 30, 40});
  
  sort_widgets_by_id(ptrs.data(), ptrs.size());

  VerifySortedIDs(ptrs, {{10, 20, 30, 40}});
}

TEST_F(PointerSorterTest, SortsReverseSortedArray) {
  auto ptrs = CreateWidgetPointers({40, 30, 20, 10});
  
  sort_widgets_by_id(ptrs.data(), ptrs.size());

  VerifySortedIDs(ptrs, {{10, 20, 30, 40}});
}

TEST_F(PointerSorterTest, HandlesDuplicateIDs) {
  auto ptrs = CreateWidgetPointers({50, 10, 10, 40});
  
  sort_widgets_by_id(ptrs.data(), ptrs.size());

  VerifySortedIDs(ptrs, {{10, 10, 40, 50}});
}

TEST_F(PointerSorterTest, SortsLargerArray) {
  auto ptrs = CreateWidgetPointers({100, 30, 50, 40, 60, 30, 10, 90, 80, 20});
  
  sort_widgets_by_id(ptrs.data(), ptrs.size());

  VerifySortedIDs(ptrs, {10, 20, 30, 30, 40, 50, 60, 80, 90, 100});
}

TEST_F(PointerSorterTest, HandlesNullPointersInArray) {
  auto ptrs = CreateWidgetPointers({10, 30});
  ptrs[1] = nullptr; // Introduce a null pointer

  // This might crash, but a robust function should handle it.
  // We can't easily verify the sorted result without more complex logic,
  // but we can check that it doesn't crash.
  EXPECT_NO_THROW(sort_widgets_by_id(ptrs.data(), ptrs.size()));
}

TEST(SwapTest, SwapsIntegerValues) {
  int a = 1, b = 2;
  swap(a, b);
  EXPECT_EQ(a, 2);
  EXPECT_EQ(b, 1);
}