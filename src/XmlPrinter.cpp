#include "XmlPrinter.h"

namespace xml 
{
    XmlPrinter::XmlPrinter(Node* tree) : node(tree)
    {
    }

    std::string XmlPrinter::getTreeXml()
    {
        tree = "";

        if (node->hasChildren())
        {
            openTag(tree);
        }
        else if (node->hasValue())
        {
            addTagWithValue(tree);
        }
        else
        {
            addEmptyTag(tree);
        }

        node->foreachChild([this](Node* child)
        {
            std::string res = child->getTreeXml();
            tree.append(res);
        });

        node->forLastChild([this](Node* child)
        {
            Node* parent = child->getParent();
            closeTag(tree, parent->getName());
        });

        return tree;
    }

    void XmlPrinter::openTag(std::string& tag)
    {
        tag.append("<");
        tag.append(node->getName());
        addAttributes(tag);
        tag.append(">");
    }

    void XmlPrinter::addAttributes(std::string& tag)
    {
        for (const auto& attribute : node->getAttributes())
        {
            tag.append(" ");
            tag.append(attribute.first);
            tag.append("=\"");
            tag.append(attribute.second);
            tag.append("\"");
        }
    }

    void XmlPrinter::addTagWithValue(std::string& tag)
    {
        openTag(tag);
        tag.append(node->getValue());
        closeTag(tag, node->getName());
    }

   void XmlPrinter::closeTag(std::string& tag, const std::string& name)
    {
        tag.append("</");
        tag.append(name);
        tag.append(">");
    }

    void XmlPrinter::addEmptyTag(std::string& tag)
    {
        tag.append("<");
        tag.append(node->getName());
        addAttributes(tag);
        tag.append("/>");
    }

} // namespace xml
