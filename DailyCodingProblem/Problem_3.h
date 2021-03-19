#pragma once

class Node
{};

std::string serialize( Node root );

Node * deserialize( std::string str );

int prob_3();