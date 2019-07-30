#ifndef RULES_API_HPP
#define RULES_API_HPP

#include "employee.hpp"
#include <boost/spirit/home/x3.hpp>
#include <iostream>
#include <string>
#include <vector>

namespace client
{
namespace parser
{
namespace x3 = boost::spirit::x3;

struct position_cache_tag;
struct person_class;
struct employee_class;
struct employees_class;

using person_type = x3::rule<person_class, ast::person>;
using employee_type = x3::rule<employee_class, ast::employee>;
using employees_type = x3::rule<employees_class, std::vector<ast::employee>>;
BOOST_SPIRIT_DECLARE(person_type);
BOOST_SPIRIT_DECLARE(employee_type);
BOOST_SPIRIT_DECLARE(employees_type);
} // namespace parser

parser::person_type person();
parser::employee_type employee();
parser::employees_type employees();
} // namespace client

#endif
