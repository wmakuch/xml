#include "Node.h"
#include "XmlPrinter.h"

namespace xml
{
    Node::Node(const std::string& name, const std::string& value)
    : name(name)
    , value(value)
    , parent(nullptr)
    {
    }

    Node::~Node()
    {
        destroy();
    }

    void Node::destroy()
    {
        for (auto child : children)
        {
            delete child.second;
        }

        children.clear();
    }

    void Node::add(Node* node)  
    {
        node->setParent(this);
        children.emplace(std::make_pair(node->getName(), node));
    }

    Node* Node::remove(const std::string& name)
    {
        auto child = children.find(name);

        if (child == children.end())
        {
            return nullptr;
        }

        child->second->setParent(nullptr);
        children.erase(name);

        return child->second;
    }

    void Node::foreachChild(std::function<void(Node*)> func)
    {
        for (auto child : children)
        {
            func(child.second);
        }
    }
 
    void Node::forLastChild(std::function<void(Node*)> func)
    {
        for (auto it = children.rbegin(); it != children.rend(); ++it)
        {
           func(it->second);
           break; // WA: crash on func(children.rbegin());
        }
    }

    std::vector<Node*> Node::getAllChildrenByName(const std::string& name)
    {
        std::vector<Node*> result;

        if (this->name == name)
        {
            result.push_back(this);
            return result;
        }

        auto range = children.equal_range(name);

        for (auto child = range.first; child != range.second; ++child)
        {
            result.push_back(child->second);
        }

        return result;
    }

    std::string Node::getTreeXml()
    {
        XmlPrinter printer(this);
        std::string str = printer.getTreeXml();
        return str;
    }

} // namespace xml
