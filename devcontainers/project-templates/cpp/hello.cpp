#include <iostream>
#include <vector>

int
main ()
{
  std::vector<int> v;
  for (int i : {5, 4, 3, 2, 1})
  {
    v.push_back (i);
  }

  for (auto val : v)
  {
    std::cout << val << ' ';
  }
  std::cout << "\nHello, World!\nWeek 3\nTEC445" << std::endl;

  int x = 1;
  int y = 9;

  while(x < 5 && y > 5) 
  {
    std::cout << "X = " << x << " Y = " << y << "\n";
    x++;
    y--;
  }
  return 0;
}
