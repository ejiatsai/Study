#include <iostream>
#include <string>

class Book{
    private:
        unsigned int isbn;
        unsigned int pagesNum;
        std::string bookName;
        std::string author;
        std::string content;
    public:
        Book(int i,int pps,std::string name){
            isbn = i;
            pagesNum = pps;
            bookName = name;
            author = "";
            content = "";
        }
        int getISBN(){
            return isbn;
        }
        int getpagesNum(){
            return pagesNum;
        }
        void setpagesNum(int p){
            if(p > 0){
                pagesNum = p;
            }
        }
        std::string getAuthor(){
            return author;
        }
        void setAuthor(std::string authorName){
            author = authorName;
        }
        std::string getcontent(){
            return content;
        }
        void setcontent(std::string c){
            content = c;
        }
        void showBook(){
            if(author.empty()){
                std::cout << "\"" << bookName << ",\" pages " << pagesNum << ", ISBN: " << isbn << std::endl;
            }
            else{
                std::cout << author << ", \"" << bookName << ",\" pages " << pagesNum << ", ISBN: " << isbn << std::endl;
            }
        }
};

int main(){
    Book b = Book(1235,18,"A Book");
    b.showBook();
    b.setAuthor("123");
    b.showBook();
    return 0;
}