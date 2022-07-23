#include "XmlBuilder.h"

namespace xml
{
    XmlBuilder& XmlBuilder::addNewNode(const std::string& name, const std::string& value)
    {
        Node* newNode = new Node(name, value);

        if(root == nullptr)
        {
            root = newNode;
        }
        else
        {
            node->add(newNode);
        }

        node = newNode;

        return *this;
    }

    XmlBuilder& XmlBuilder::addNextNode(const std::string& parent, const std::string& name, const std::string& value)
    {
        Node* newNode = new Node(name, value);

        std::vector<Node*> children = root->getAllChildrenByName(parent);

        if (children.empty())
        {
            return *this;
        }

        auto child = children.rbegin();

        (*child)->add(newNode);
        node = newNode;
        return *this;
    }

    XmlBuilder& XmlBuilder::addAttribute(const std::string& name, const std::string& value)
    {
        if (node != nullptr)
        {
            node->addAttribute(name, value);
        }

        return *this;
    }

    Node* XmlBuilder::build()
    {
        return root;
    }

} // namespace xml
