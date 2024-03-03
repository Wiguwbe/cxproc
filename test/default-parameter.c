int foo(int a, int b=5)
{
  return a+b;
}

int main()
{
  foo(7);
  foo(7, 5);
  return 0;
}
