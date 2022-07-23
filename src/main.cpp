#include <iostream>
#include <memory>
#include "XmlBuilder.h"

void test()
{
    // <members>
    //    <member name="John" surename="Smith">
    //        <location>New York</location>
    //        <phone>458216985</phone>
    //    </member>
    //    <member name="Jack" surename="Ma">
    //        <location>Shanghai</location>
    //        <phone>452369875</phone>
    //    </member>
    // </members>

    xml::XmlBuilder builder;
    xml::Node* node = builder.addNewNode("members")
                             .addNewNode("member")
                             .addAttribute("name","John")
                             .addAttribute("surename","Smith")
                             .addNextNode("member", "phone", "458216985")
                             .addNextNode("member", "location", "New York")
                             .addNextNode("members", "member")
                             .addAttribute("name","Jakc")
                             .addAttribute("surename","Ma")
                             .addNextNode("member", "phone", "452369875")
                             .addNextNode("member", "location", "Shanghai")
                             .build();

    node->printTreeXml();
    delete node;
}

void pauseIfWindows()
{
#ifdef _WIN32
    system("PAUSE");
#endif
}

int main()
{
    test();
    pauseIfWindows();

}
