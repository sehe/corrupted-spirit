#include "rules.hpp"
#include "config.hpp"
#include <boost/spirit/home/x3.hpp>
#include <string>

namespace client
{
	namespace parser
	{
		BOOST_SPIRIT_INSTANTIATE(person_type, iterator_type, context_type);
		BOOST_SPIRIT_INSTANTIATE(employee_type, iterator_type, context_type);
		BOOST_SPIRIT_INSTANTIATE(employees_type, iterator_type, context_type);
	} // namespace parser
} // namespace client