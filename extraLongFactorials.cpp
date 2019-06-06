void extraLongFactorials(int n)
{
  if (n < 0) return;

  if (n == 0 || n == 1)
  {
    cout << "1" << endl;
    return;
  }

  if (n == 2)
  {
    cout << "2" << endl;
    return;
  }

  string num = "";


  vector<unsigned long long> *result = new vector<unsigned long long>(64);
  unsigned int limit = static_cast<unsigned int>(1e+3);
  (*result)[0] = 2;

  for (short a = 3, b = 0; a <= n; ++a)
  {
    unsigned int tmp = 0;
    for (short c = 0; c <= b; ++c)
    {
      (*result)[c] *= a;
      (*result)[c] += tmp;
      if ((*result)[c] >= limit)
      {
        tmp = (*result)[c] / limit;
        (*result)[c] %= limit;
        if (b == c)  ++b;
      } 
      else
      {
        tmp = 0;
      }
    }
  }
  string tmp = "";
  for (size_t a = (*result).size() - 1; a >= 0 && a < (*result).size(); --a)
  {
    unsigned int hund, dec, dig;
    string w = "";
        
    hund = (*result)[a] / 100;
    (*result)[a] %= 100;
    
    
    dec = (*result)[a] / 10;
    (*result)[a] %= 10;
    
    dig = (*result)[a];

    w = to_string(hund) + to_string(dec) + to_string(dig);

    tmp += w;
  }

  int index = 0;
  while (tmp[index] == '0') {
    ++index;
  }
  num.assign(tmp, index, tmp.length() - index);
  cout << num << endl;

}
