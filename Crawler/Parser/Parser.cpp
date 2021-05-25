#include "Parser.hpp"
#include <gumbo.h>
#include <assert.h>
#include <optional>

Parser::Parser(const std::string& url,const std::string& html){
    this->url = url;
    this->html = html;

}

//relative to absolute????
void Parser::extractUrls(GumboNode* node){
    //vercnum enq node-y u ayd nodeic sksac man enq galis ayn tagery voronc mej link ka(a tagery)
    if (node->type != GUMBO_NODE_ELEMENT) {
        return;
    }

    if (node->v.element.tag == GUMBO_TAG_A) {
        /**
         * Given a vector of GumboAttributes, look up the one with the specified name
         * and return it, or NULL if no such attribute exists.  This uses a
         * case-insensitive match, as HTML is case-insensitive.
         */
        GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
        if(href == NULL || href->value == NULL){
            return;
        }
        /*
        boost::regex ex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");
        boost::cmatch what;
        if(regex_match(url.c_str(), what, ex)) 
        {
            cout << "domain:" << string(what[2].first, what[2].second) << endl;
        }
        */
        this->urls.push_back(href->value);
    }

    //ete orinak sksum enq html tagic iharke da link chi, bayc karox e ira mej parunakel a tager,dra hamar rekursiayov pttvum enq 
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        this->extractUrls(static_cast<GumboNode*>(children->data[i]));//GumboNode*-new expression
    }
}


std::string Parser::extractCleanText(GumboNode* node) const {
    if (node->type == GUMBO_NODE_TEXT) {
        return std::string(node->v.text.text);
    } 
    else if (node->type == GUMBO_NODE_ELEMENT && node->v.element.tag != GUMBO_TAG_SCRIPT && node->v.element.tag != GUMBO_TAG_STYLE) {
        std::string contents;
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            const std::string text = this->extractCleanText(static_cast<GumboNode*>(children->data[i]));
            if (i != 0 && !text.empty()) {
                contents.append(" ");
            }
            contents.append(text);
        }
        return contents;
    } 
    else {
        return "";
    }
}

void Parser::extractTitle(GumboNode* node){
    if (node->type != GUMBO_NODE_ELEMENT) {
        return;
    }
    GumboVector* children = &node->v.element.children;
	if (node->v.element.tag == GUMBO_TAG_TITLE && children->length != 0) {
		this->title = std::string(static_cast<GumboNode*>(children->data[0])->v.text.text);
        return;
	}

	for (size_t i = 0; i < children->length; ++i) {
		this->extractTitle(static_cast<GumboNode*>(children->data[i]));
	}
}

void Parser::extractDescription(GumboNode* node) {
    if (node->type != GUMBO_NODE_ELEMENT) {
        return;
    }
    
    if (node->v.element.tag == GUMBO_TAG_META) {
        GumboAttribute* name = gumbo_get_attribute(&node->v.element.attributes, "name");
        if (name == nullptr || name->value == nullptr || name->value != std::string("description")) {
            return;
        }
        
        GumboAttribute* content = gumbo_get_attribute(&node->v.element.attributes, "content");
        if (content == nullptr || content->value == nullptr) {
            return;
        }

        this->description = content->value;
        return;
    }
    
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        this->extractDescription(static_cast<GumboNode*>(children->data[i]));
    }
    
    return;
}

void Parser::parse() {
    GumboOutput* output = gumbo_parse(this->html.c_str());
    this->extractUrls(output->root);
    this->allText = this->extractCleanText(output->root);
    this->extractTitle(output->root);
    this->extractDescription(output->root);
    
    gumbo_destroy_output(&kGumboDefaultOptions, output);
}

const std::vector<std::string>& Parser::getUrls() const {
    return this->urls;
}

const  std::string& Parser::getTitle() const {
    return this->title;
}

const  std::string& Parser::getDescription() const {
    return this->description;
}

const  std::string& Parser::getAllText() const {
    return this->allText;
}