#ifndef INTERVAL_H
#define INTERVAL_H
#include "global.h"
//区间类
class Interval {
    public:
        Interval() : m_start_(MY_INFINITY), m_end_(-MY_INFINITY) {}
        Interval(double a, double b) : m_start_(a), m_end_(b) {}
        double start() const { return m_start_; }
        double end() const { return m_end_; }
        bool contains(double val) const { return val >= m_start_ && val <= m_end_; } //判断x是否在闭区间内
        bool surrounds(double val) const { return val > m_start_ && val < m_end_;} //判断x是否在开区间内

        static const Interval Empty;
        static const Interval Universe;
    private:
        double m_start_;
        double m_end_;
};
#endif