// @copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2017/11/03.

#ifndef ZAPI_TEST_DUMMYEXT_NATIVE_CLASSES_H
#define ZAPI_TEST_DUMMYEXT_NATIVE_CLASSES_H

#include "zapi/ZendApi.h"
#include <string>
#include <vector>

namespace dummyext 
{

using zapi::lang::StdClass;
using zapi::ds::Variant;
using zapi::ds::NumericVariant;
using zapi::ds::StringVariant;
using zapi::ds::ArrayVariant;

// normal classes definitions

class Person : public StdClass
{
public:
   Person();
   void showName();
   void print_sum(NumericVariant argQuantity, ...);
   void setAge(const NumericVariant &age);
   int getAge();
   
   Variant getName();
   int addTwoNum(const NumericVariant &num1, const NumericVariant &num2);
   int addSum(NumericVariant argQuantity, ...);
   // access level test method
   void protectedMethod();
   void privateMethod();
   
   static void staticShowName();
   static StringVariant concatStr(const StringVariant &lhs, const StringVariant &rhs);
   static void staticProtectedMethod();
   static void staticPrivateMethod();
   static void makeNewPerson();
private:
   /**
     *  The initial value
     *  @var    int
     */
   std::string m_name;
   int m_age;
};


class Address : public StdClass
{
public:
   Address();
protected:
   std::string address;
};

class ConstructAndDestruct : public StdClass
{
public:
   void __construct();
   void __destruct();
};

class EmptyClass : public StdClass
{};

// for test class and interface inherit
class A : public StdClass
{
public:
   void printInfo();
   void changeNameByRef(StringVariant &name);
   void privateAMethod();
   void protectedAMethod();
};

class B : public StdClass
{
public:
   void printInfo();
   void showSomething();
   void calculateSumByRef(NumericVariant argQuantity, NumericVariant retval, ...);
   Variant addTwoNumber(NumericVariant &lhs, NumericVariant &rhs);
   void privateBMethod();
   void protectedBMethod();
};

class C : public StdClass
{
public:
   void printInfo();
   void testCallParentPassRefArg();
   void testCallParentWithReturn();
   void testGetObjectVaraintPtr();
   void privateCMethod();
   void protectedCMethod();
   void methodOfA();
   void protectedMethodOfA();
   void privateMethodOfA();
};

class IterateTestClass : 
      public StdClass, 
      public zapi::protocol::Traversable, 
      public zapi::protocol::AbstractIterator,
      public zapi::protocol::Countable,
      public zapi::protocol::ArrayAccess
{
   using IteratorType = std::vector<std::pair<std::string, std::string>>::iterator;
public:
   IterateTestClass();
   virtual AbstractIterator *getIterator();
   virtual bool valid();
   virtual Variant current();
   virtual Variant key();
   virtual void next();
   virtual void rewind();
   virtual zapi_long count();
   
   virtual bool offsetExists(Variant offset);
   virtual void offsetSet(Variant offset, Variant value);
   virtual Variant offsetGet(Variant offset);
   virtual void offsetUnset(Variant offset);
   virtual ~IterateTestClass();
protected:
   // save iterator object
   std::shared_ptr<AbstractIterator> m_iterator;
   IteratorType m_currentIter;
   std::vector<std::pair<std::string, std::string>> m_items;
};


} // dummyext

#endif // ZAPI_TEST_DUMMYEXT_NATIVE_CLASSES_H
