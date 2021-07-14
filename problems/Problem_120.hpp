#pragma once

/*
Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. And in every
even call of getInstance(), return the first instance and in every odd call of getInstance(), return the second
instance.
*/

class Singleton
{
private:
  int value = 0;

public:
  static Singleton & getInstance()
  {
    static int       count = getCount();
    static Singleton singleton_even;
    static Singleton singleton_odd;

    if( count % 2 == 0 ) { return singleton_even; }
    else
    {
      return singleton_odd;
    }
  }

  int  getValue() const { return value; }
  void setValue( int x ) { value = x; }

private:
  Singleton() {}

  static int getCount()
  {
    static int counter;
    return counter++;
  }
};
