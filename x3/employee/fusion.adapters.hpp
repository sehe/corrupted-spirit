#ifndef FUSION_ADAPTERS
#define FUSION_ADAPTERS

#include "person.hpp"
#include "employee.hpp"
#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(client::ast::person,
						  age, given_name, family_name)

BOOST_FUSION_ADAPT_STRUCT(client::ast::employee,
						  who, salary)

#endif
