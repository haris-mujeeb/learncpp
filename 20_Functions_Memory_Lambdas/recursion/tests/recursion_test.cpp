#include <gtest/gtest.h>
#include "virtual_file_system_analyzer.hpp"


class VFS_Analyzer_Tests : public ::testing::Test {
protected:
  std::unique_ptr<Node> root;

  void SetUp() override {
    // root->addChild("bin", 0, true);
    // OR
    root = std::make_unique<Node>("root");
    auto bin = std::make_unique<Node>("bin");
    auto ls = std::make_unique<Node>("ls", 100, false);
    auto home = std::make_unique<Node>("home");
    auto user = std::make_unique<Node>("user");
    auto notes = std::make_unique<Node>("notes.txt", 50, false);
    auto photo = std::make_unique<Node>("photo.jpg", 200, false);
    user->addChild(std::move(notes));
    user->addChild(std::move(photo));
    home->addChild(std::move(user));
    root->addChild(std::move(home));
    bin->addChild(std::move(ls));
    root->addChild(std::move(bin));
  }
};


TEST_F(VFS_Analyzer_Tests, RootInitialization) {
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->m_name, "root");
  EXPECT_EQ(root->m_size, 0);
  EXPECT_EQ(root->is_directory, true);
}


TEST_F(VFS_Analyzer_Tests, CheckChildProperties) {
  Node* binNode = root->getChild("bin");
  ASSERT_NE(binNode, nullptr);
  EXPECT_EQ(binNode->m_name, "bin");
  EXPECT_EQ(binNode->m_size, 0);
  EXPECT_EQ(binNode->is_directory, true);
}


TEST_F(VFS_Analyzer_Tests, FindPath) {
  ASSERT_EQ(findPath(root.get(), "bin"), "/root/bin");
  ASSERT_EQ(findPath(root.get(), "ls"), "/root/bin/ls");
  ASSERT_EQ(findPath(root.get(), "user"), "/root/home/user");
  ASSERT_EQ(findPath(root.get(), "notes.txt"), "/root/home/user/notes.txt");
  ASSERT_EQ(findPath(root.get(), "photo.jpg"), "/root/home/user/photo.jpg");
}

TEST_F(VFS_Analyzer_Tests, GetTotalSize) {
  ASSERT_EQ(getTotalSize(root.get()), 350);

  Node* notes = root->getChild("notes.txt");
  ASSERT_EQ(getTotalSize(notes), 50);

  Node* photo = root->getChild("photo.jpg");
  ASSERT_EQ(getTotalSize(photo), 200);
  
  Node* ls = root->getChild("ls");
  ASSERT_EQ(getTotalSize(ls), 100);
}
  