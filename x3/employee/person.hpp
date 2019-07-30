#ifndef PERSON_HPP
#define PERSON_HPP

#include <boost/fusion/include/io.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

namespace client
{
namespace ast
{
namespace x3 = boost::spirit::x3;

struct person : x3::position_tagged
{
	int age;
	std::string given_name;
	std::string family_name;
};

using boost::fusion::operator<<;
} // namespace ast
} // namespace client

#endif