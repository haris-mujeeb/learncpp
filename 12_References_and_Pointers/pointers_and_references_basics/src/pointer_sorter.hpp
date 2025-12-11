#ifndef POINTER_SORTER_HPP
#define POINTER_SORTER_HPP

struct Widget
{
  int id;
};

void sort_widgets_by_id(const Widget* widget_pointers[], int size);

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

#endif // POINTER_SORTER_HPP