class A
{
public:
  A() {};

private:
  A(const A& object)=delete;
  A &operator=(const A& object)=delete;
};
