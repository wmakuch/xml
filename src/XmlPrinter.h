#pragma once

#include "Node.h"

namespace xml
{
    class XmlPrinter 
    {
    public:
        XmlPrinter(Node* tree);
        ~XmlPrinter() = default;

        std::string getTreeXml();

    private:
        void openTag(std::string& tag);
        void addTagWithValue(std::string& tag);
        void addEmptyTag(std::string& tag);
        void closeTag(std::string& tag, const std::string& name);
        void addAttributes(std::string& tag);

        std::string tree;
        Node* node;
    };

} // namespace xml
