#ifndef VFS_ANALYZER_HPP
#define VFS_ANALYZER_HPP

#include <string>
#include <vector>
#include <memory>

class Node {
  public:
  std::string m_name;
  int m_size;   // for dir size = 0
  bool is_directory;
  std::vector<std::unique_ptr<Node>> m_children;
  
  Node(std::string name, int size = 0, bool is_directory = true) 
  : m_name(name), m_size(size), is_directory(is_directory){}
  
  Node(std::string name, int size, bool is_directory, std::unique_ptr<Node> child) 
  : m_name(name), m_size(size), is_directory(is_directory) 
  {
    if (child) {
      m_children.push_back(std::move(child));
    }
  }

  void addChild(std::string name, int size, bool isDir);
  void addChild(std::unique_ptr<Node> child);
  
  Node* getChild(std::string child);
};


void Node::addChild(std::string name, int size, bool isDir) {
  m_children.push_back(std::make_unique<Node>(name, size, isDir));
}


void Node::addChild(std::unique_ptr<Node> child) {
  m_children.push_back(std::move(child));
}


Node* Node::getChild(std::string child_name) {
  for (const auto& child : m_children) {
    if (!child ) return nullptr;
    
    if (child->m_name == child_name) {
      return child.get();
    } 
  
    Node* ptr = child->getChild(child_name);
    if (ptr) {
      return ptr;
    }
  }
  return nullptr;
}


int getTotalSize(const Node* node) {
  if (node == nullptr) return 0;

  int sum = node->m_size;

  for (const auto& child : node->m_children) {
    sum += getTotalSize(child.get());
  }
  
  return sum;
}


std::string findPath(const Node* node, const std::string& targetName, std::string currentPath = "") {
  if (node == nullptr) throw std::runtime_error("Node is nullptr.");
  currentPath += "/" + node->m_name;

  if(node->m_name == targetName){
    return currentPath;
  } 

  std::string result;
  for (auto& child : node->m_children) {
    result = findPath(child.get(), targetName, currentPath);
    if (!result.empty()) {
      return result;
    } 
  }

  return "";
}

#endif // VFS_ANALYZER_HPP