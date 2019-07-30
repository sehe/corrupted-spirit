#include "employee.hpp"
#include "fusion.adapters.hpp"
#include "rules_api.hpp"

using namespace std;

namespace x3 = boost::spirit::x3;
namespace ascii = boost::spirit::x3::ascii;

void parse_employee()
{
	string input{R"({34,"Mario","Rossi",1251.42})"};
	client::ast::employee output;
	bool isParsed = x3::phrase_parse(cbegin(input), cend(input), client::employee(), ascii::space, output);
	if (isParsed)
	{
		cout << boost::fusion::tuple_open('[');
		cout << boost::fusion::tuple_close(']');
		cout << boost::fusion::tuple_delimiter(", ");
		cout << output << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////
// Our main parse entry point
///////////////////////////////////////////////////////////////////////////////

using iterator_type = std::string::const_iterator;
using position_cache = boost::spirit::x3::position_cache<vector<iterator_type>>;

vector<client::ast::employee> parse(string const &input, position_cache &positions)
{
	using boost::spirit::x3::ascii::space;

	vector<client::ast::employee> ast;
	iterator_type iter = input.begin();
	iterator_type const end = input.end();

	using boost::spirit::x3::with;

	// Our parser
	using client::parser::position_cache_tag;

	auto const parser =
		// we pass our position_cache to the parser so we can access
		// it later in our on_sucess handlers
		with<position_cache_tag>(ref(positions))[client::employees()];

	bool r = phrase_parse(iter, end, parser, space, ast);

	if (r && iter == end)
	{
		cout << boost::fusion::tuple_open('[');
		cout << boost::fusion::tuple_close(']');
		cout << boost::fusion::tuple_delimiter(", ");

		cout << "-------------------------\n";
		cout << "Parsing succeeded\n";

		for (auto const &emp : ast)
		{
			cout << "got: " << emp << endl;
		}
		cout << "\n-------------------------\n";
	}
	else
	{
		cout << "-------------------------\n";
		cout << "Parsing failed\n";
		cout << "-------------------------\n";
		ast.clear();
	}
	return ast;
}

void parse_employees()
{
	// Sample input:

	string input = R"(
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
	auto pos = positions.position_of(ast[1]); // zero based of course!
	cout << "Here's the 2nd employee:" << endl;
	cout << string(pos.begin(), pos.end()) << endl;
	cout << "-------------------------\n";
}

int main()
{
	parse_employees();
	return 0;
}