#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3.hpp>
#include <string>

namespace client
{
namespace parser
{
namespace x3 = boost::spirit::x3;

using iterator_type = std::string::const_iterator;

struct position_cache_tag;
using position_cache = boost::spirit::x3::position_cache<std::vector<iterator_type>>;

using simple_context_type = x3::phrase_parse_context<x3::ascii::space_type>::type;

using context_type = boost::spirit::x3::context<
    client::parser::position_cache_tag,
    position_cache, 
    simple_context_type
>;
} // namespace parser
} // namespace client

#endif
