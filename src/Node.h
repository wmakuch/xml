#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>

namespace xml
{
    class Node 
    {
    public:
        Node(const std::string& name, const std::string& value = "");
        ~Node();

        void add(Node* node);
        Node* remove(const std::string& name);
        std::vector<Node*> getAllChildrenByName(const std::string& name);
        void foreachChild(std::function<void(Node*)> func);
        void forLastChild(std::function<void(Node*)> func);
        std::string getTreeXml();

        inline std::string getName() const
        {
            return name;
        }

        inline Node* getParent() const
        {
            return parent;
        }

        inline void setParent(Node* node)
        {
            parent = node;
        }

        inline void addAttribute(const std::string& name, const std::string& value)
        {         
            attributes.emplace(name, value);
        }

        inline std::map<std::string, std::string> getAttributes() const
        {
            return attributes;
        }

        inline bool hasValue() const
        {
           return value != "";
        }

        inline std::string getValue() const
        {
            return value;
        }

        inline bool hasChildren() const
        {
            return !children.empty();
        }

        inline void printTreeXml()
        {
            std::cout << getTreeXml() << std::endl; 
        }

    private:
        void destroy();

        std::string name;
        std::string value;

        Node* parent;
        std::multimap<std::string, Node*> children;
        std::map<std::string, std::string> attributes;
    };

} // namespace xml
