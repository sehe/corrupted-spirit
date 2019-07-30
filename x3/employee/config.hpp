#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace client
{
namespace parser
{
namespace x3 = boost::spirit::x3;

using iterator_type = std::string::const_iterator;
using context_type = x3::phrase_parse_context<x3::ascii::space_type>::type;
} // namespace parser
} // namespace client

#endif
