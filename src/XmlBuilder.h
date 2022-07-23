#pragma once

#include "Node.h"

namespace xml
{
    class XmlBuilder
    {
    public:
        XmlBuilder() : node(nullptr), root(nullptr) {}
        ~XmlBuilder() = default;

        XmlBuilder& addNewNode(const std::string& name, const std::string& value = "");
        XmlBuilder& addNextNode(const std::string& parent, const std::string& name, const std::string& value = "");
        XmlBuilder& addAttribute(const std::string& name, const std::string& value);
        Node* build();

    private:
        Node* node;
        Node* root;
    };

} // namespace xml
