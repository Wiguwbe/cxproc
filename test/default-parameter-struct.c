struct foo {
  int a;
  int b;
};

int bar(struct foo f = {1,2})
{
  return f.a + f.b;
}

int main()
{
  return bar();
}
