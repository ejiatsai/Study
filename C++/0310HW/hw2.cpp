#include <iostream>
#include <string>

class Book{
    private:
        unsigned int isbn;
        unsigned int pagesNum;
        unsigned int word_a_page;
        std::string bookName;
        std::string author;
        std::string content;
    public:
        Book(int i,int pps,std::string name){
            isbn = i;
            pagesNum = pps;
            bookName = name;
            word_a_page = 5;
            author = "";
            content = "";
        }
        void pageCounter(){
            if(content.size() % 5 == 0){
                pagesNum = content.size() / word_a_page;
            }
            else{
                pagesNum = content.size() / word_a_page + 1;
            }
        }
        int getword_a_page(){
            return word_a_page;
        }
        int getISBN(){
            return isbn;
        }
        int getpagesNum(){
            pageCounter();
            return pagesNum;
        }
        void setpagesNum(int p){
            if(p > 0){
                pagesNum = p;
            }
        }
        std::string getAuthor(){
            if(author.empty()){
                return "";
            }
            else{
                return author;
            }
        }
        void setAuthor(std::string authorName){
            author = authorName;
        }
        std::string getcontent(){
            if(content.empty()){
                return "";
            }
            else{
                return content;
            }
        }
        void setcontent(std::string c){
            content = c;
            pageCounter();
        }
        void addcontent(std::string c){
            content += c;
            pageCounter();
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

class BookWriter{
    private:
        std::string writer;
    public:
        BookWriter(std::string bookAuthor){
            writer = bookAuthor;
        }
        Book createBook(int isbn,std::string bookname,std::string bookcontent){
            Book b = Book(isbn,0,bookname);
            b.setAuthor(writer);
            b.setcontent(bookcontent);
            return b;
        }
        Book writeBook(Book &b,std::string addBookContent){
            b.addcontent(addBookContent);
            return b;
        }
};

class BookReader{
    private:
        std::string reader;
    public:
        BookReader(std::string bookReader){
            reader = bookReader;
        }
        std::string readBook(Book &b,int readPage){
            int pagesNum = b.getpagesNum();
            if(readPage > pagesNum){
                return "the page is not exist";
            }
            else{
                std::string wholeBook = b.getcontent();
                int word_a_page = b.getword_a_page();
                int start = word_a_page *(readPage - 1);
                std::string readContent = wholeBook.substr(start,word_a_page);
                return readContent;
            }
        }
        Book tearBook(Book &b){
            b.setcontent("");
        }
};

int main(){
    Book b = Book(1235,18,"A Book");
    b.showBook();
    BookWriter wa = BookWriter("123");
    BookReader rb = BookReader ("456");
    Book book123 = wa.createBook(1232,"A Note","hahaha");
    wa.writeBook(book123,"1324645675");
    book123.showBook();
    std::cout << rb.readBook(book123,3) << std::endl;
    rb.tearBook(book123);
    std::cout << book123.getpagesNum()<< std::endl;
    book123.showBook();
    return 0;
}