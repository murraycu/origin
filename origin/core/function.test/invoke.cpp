// This file is distributed under the MIT License. See the accompanying file
// LICENSE.txt or http://www.opensource.org/licenses/mit-license.php for terms
// and conditions.

#include <iostream>

#include <origin/core/type.hpp>
#include <origin/core/function.hpp>

struct X { };

bool even(int n) { return n % 2 == 0; }

struct even_fn 
{
  bool operator()(int n) const { return even(n); }
};

struct S {
  void f() { }
  void fc() const { }
  void g(int) { }
};

static_assert(origin::Invokable<decltype(even), int>(), "");

static_assert(origin::Invokable<even_fn, int>(), "");

static_assert(origin::Invokable<decltype(&S::f), S*>(), "");
static_assert(origin::Invokable<decltype(&S::fc), const S*>(), "");
static_assert(origin::Invokable<decltype(&S::g), S*, int>(), "");

static_assert(!origin::Invokable<decltype(even), X>(), "");

int main() 
{ 
}
