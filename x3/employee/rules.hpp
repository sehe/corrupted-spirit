#ifndef RULES_HPP
#define RULES_HPP

#include "employee.hpp"
#include "fusion.adapters.hpp"
#include "rules_api.hpp"
#include <boost/spirit/home/x3.hpp>
#include <string>

namespace client
{
namespace parser
{
namespace x3 = boost::spirit::x3;
namespace ascii = boost::spirit::x3::ascii;

///////////////////////////////////////////////////////////////////////
//  Our annotation handler
///////////////////////////////////////////////////////////////////////

// tag used to get the position cache from the context
struct annotate_position
{
	template <typename T, typename Iterator, typename Context>
	inline void on_success(const Iterator &first, const Iterator &last, T &ast, const Context &context)
	{
		auto &position_cache = x3::get<position_cache_tag>(context);
		position_cache.annotate(ast, first, last);
	}
};

using ascii::char_;
using x3::double_;
using x3::int_;
using x3::lexeme;

const x3::rule<class quoted_string, std::string> quoted_string = "quoted_string";
person_type person = "person";
employee_type employee = "employee";
employees_type employees = "employees";
const auto quoted_string_def = lexeme['"' >> +(char_ - '"') >> '"'];
const auto person_def = int_ >> ',' >> quoted_string >> ',' >> quoted_string;
const auto employee_def = '{' >> person >> ',' >> double_ >> '}';
const auto employees_def = employee >> *(',' >> employee);
BOOST_SPIRIT_DEFINE(quoted_string, person, employee, employees)

struct person_class : annotate_position
{
};
struct employee_class : annotate_position
{
};
} // namespace parser

parser::person_type person()
{
	return parser::person;
}

parser::employee_type employee()
{
	return parser::employee;
}

parser::employees_type employees()
{
	return parser::employees;
}
} // namespace client

#endif
