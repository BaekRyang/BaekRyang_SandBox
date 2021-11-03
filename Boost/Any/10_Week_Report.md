#Boost::Any Algorithm 분석

##사용방법

다음은 Boost Libraries에 있는 Any의 사용법이다.
```C++
#include <list>
#include <boost/any.hpp>

using boost::any_cast;
typedef std::list<boost::any> many;

void append_int(many & values, int value)
{
    boost::any to_append = value;
    values.push_back(to_append);
}

void append_string(many & values, const std::string & value)
{
    values.push_back(value);
}

void append_char_ptr(many & values, const char * value)
{
    values.push_back(value);
}

void append_any(many & values, const boost::any & value)
{
    values.push_back(value);
}

void append_nothing(many & values)
{
    values.push_back(boost::any());
}
```