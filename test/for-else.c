
int main()
{
  int i;
  for (i=0; i<5; i++)
  {
    break;
  }
  else
  {
    // we only care that the labels are there
  }

  for(i=0; i<1; i++)
  {
    break;
  }
  // else label should still be there

  while(i < 10)
  {
    break;
  }
  else
  {

  }

  return 0;
}
