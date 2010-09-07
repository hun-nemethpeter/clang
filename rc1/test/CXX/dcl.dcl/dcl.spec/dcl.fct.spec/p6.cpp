// RUN: %clang_cc1 -verify %s

class A {
public:
  explicit A();
  
  explicit operator int(); // expected-warning {{explicit conversion functions are a C++0x extension}}

  explicit void f0(); // expected-error {{'explicit' can only be applied to a constructor or conversion function}}
  
  operator bool();
};

explicit A::A() { } // expected-error {{'explicit' can only be specified inside the class definition}}
explicit A::operator bool() { return false; }  // expected-warning {{explicit conversion functions are a C++0x extension}}\
                                               // expected-error {{'explicit' can only be specified inside the class definition}}
