#include <cassert>
#include <iostream>

class FixedPoint2{
    private:

        std::int16_t m_whole {};
        std::int8_t m_fractional {};

    public:

        FixedPoint2(std::int16_t whole, std::int8_t fractional)
            : m_whole {whole}, m_fractional {fractional}
        {
            if (m_whole < 0 || m_fractional < 0)
            {
                if (m_whole > 0)
                    m_whole = -m_whole;

                if (m_fractional > 0)
                    m_fractional = -m_fractional;
            }

            m_whole += m_fractional / 100;
		    m_fractional = m_fractional % 100;

        }

        FixedPoint2(double d) :
            FixedPoint2{
                static_cast<std::int16_t>(std::trunc(d)),
                static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100)
            }
	    {
	    }

        operator double() const {
            return m_whole + (static_cast<double>(m_fractional) / 100);
        }

        FixedPoint2 operator-() const
        {
            return FixedPoint2
            {
                static_cast<std::int16_t>(-m_whole),
                static_cast<std::int8_t>(-m_fractional)
            };
        }

        friend bool operator== (const FixedPoint2& point1, const FixedPoint2& point2);

};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& point){
    out << static_cast<double>(point);
    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& point){
    double d {};
    in >> d;
    point = FixedPoint2 {d};
    return in;
}

bool operator== (const FixedPoint2& point1, const FixedPoint2& point2){
    return (point1.m_whole == point2.m_whole) && (point1.m_fractional == point2.m_fractional);
}

FixedPoint2 operator+ (const FixedPoint2& point1, const FixedPoint2& point2){
    return static_cast<double>(point1) + static_cast<double>(point2);
}

int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
