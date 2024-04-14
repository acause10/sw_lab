#ifndef SEL_COMPARE_H
#define SEL_COMPARE_H

class Compare
{
  public:
    Compare();
    Compare(double epsilon);
    ~Compare();

    bool isFuzzyEqual(double value1, double value2);
    bool isFuzzyGreater(double value1, double value2);
    bool isFuzzySmaller(double value1, double value2);
    bool isStrictFuzzyGreater(double value1, double value2);
    bool isStrictFuzzySmaller(double value1, double value2);

  private:
    double epsilon_;
};

#endif  // SEL_COMPARE_H
