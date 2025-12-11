#include "pointer_sorter.hpp"


void sort_widgets_by_id(const Widget* widget_ptrs[], int size) {
  if (widget_ptrs == nullptr) {
    return;
  }
  
  for (int i = 0; i < size - 1; i++) {
      int min_idx = i;

    for (int j = i + 1; j < size; j++) {
      if (widget_ptrs[j] && widget_ptrs[min_idx] && widget_ptrs[j]->id < widget_ptrs[min_idx]->id) {
        min_idx = j;
      }
    }

    swap(widget_ptrs[i], widget_ptrs[min_idx]);
  }
}