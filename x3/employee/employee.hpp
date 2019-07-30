#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "person.hpp"
#include <boost/fusion/include/io.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

namespace client
{
namespace ast
{
namespace x3 = boost::spirit::x3;

struct employee : x3::position_tagged
{
	person who;
	double salary;
};

using boost::fusion::operator<<;
} // namespace ast
} // namespace client

#endif
