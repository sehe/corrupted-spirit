#include "employee.hpp"
#include "fusion.adapters.hpp"
#include "rules_api.hpp"

namespace x3 = boost::spirit::x3;
namespace ascii = x3::ascii;

///////////////////////////////////////////////////////////////////////////////
// Our main parse entry point
///////////////////////////////////////////////////////////////////////////////

using iterator_type = std::string::const_iterator;
using position_cache = boost::spirit::x3::position_cache<std::vector<iterator_type>>;

std::vector<client::ast::employee> parse(std::string const &input, position_cache &positions)
{
	using boost::spirit::x3::ascii::space;

    std::vector<client::ast::employee> ast;
	iterator_type iter = input.begin();
	iterator_type const end = input.end();

	using boost::spirit::x3::with;

	// Our parser
	using client::parser::position_cache_tag;

	auto const parser =
		// we pass our position_cache to the parser so we can access
		// it later in our on_sucess handlers
		with<position_cache_tag>(positions)[client::employees()];

	bool r = phrase_parse(iter, end, parser, space, ast);

	if (r && iter == end)
	{
        std::cout << boost::fusion::tuple_open('[');
        std::cout << boost::fusion::tuple_close(']');
        std::cout << boost::fusion::tuple_delimiter(", ");

        std::cout << "-------------------------\n";
        std::cout << "Parsing succeeded\n";

		for (auto const &emp : ast)
		{
            std::cout << "got: " << emp << std::endl;
		}
        std::cout << "\n-------------------------\n";
	}
	else
	{
        std::cout << "-------------------------\n";
        std::cout << "Parsing failed\n";
        std::cout << "-------------------------\n";
		ast.clear();
	}
	return ast;
}

void parse_employees()
{
	// Sample input:

    std::string input = R"(
	{
		23,
		"Amanda",
		"Stefanski",
		1000.99
	},
	{
		35,
		"Angie",
		"Chilcote",
		2000.99
	},
	{
		43,
		"Dannie",
		"Dillinger",
		3000.99
	},
	{
		22,
		"Dorene",
		"Dole",
		2500.99
	},
	{
		38,
		"Rossana",
		"Rafferty",
		5000.99
	}
	)";

	position_cache positions{input.begin(), input.end()};
	auto ast = parse(input, positions);
	// Get the source of the 2nd employee and print it
    if (ast.size()>1)
    {
        auto pos = positions.position_of(ast[1]); // zero based of course!
        std::cout << "Here's the 2nd employee:" << std::endl;
        std::cout << std::string(pos.begin(), pos.end()) << std::endl;
    }
    std::cout << "-------------------------\n";
}

int main()
{
	parse_employees();
	return 0;
}
