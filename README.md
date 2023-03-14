# Stopword-Removal

A C++ class that removes stop words from your `std::string`.

Usage:

```cpp
// MyFile.cpp

#include <iostream>

#include "StopWordRemoval.hpp"

int main()
{
  std::string StringToFilter = "This is a string to filter.";
  SWR remover;
  std::string FilteredString = remover.RemoveStopWords(StringToFilter);
  std::cout << FilteredString << std::endl;
  return 0;
}

```
