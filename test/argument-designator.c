int foo(int a, int b=5, int c=6)
{
  return a+b+c;
}

int main()
{
  foo(7);
  foo(7, .b=2);
  foo(7, 1, .c=12);
  foo(.c=3, .b=2, .a = 1);
  return 0;
}
