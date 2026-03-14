#include <iostream>
#include <string>
#include <vector>

class Book{
    private:
        unsigned int isbn;
        unsigned int pagesNum;
        unsigned int word_a_page;
        std::string bookName;
        std::string author;
        std::string content;
        void setcontent(std::string c){
            content = c;
            pageCounter();
        }
        void addcontent(std::string c){
            content += c;
            pageCounter();
        }
        friend class BookWriter;
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
        void tearbook(int start){
            content.erase(start,word_a_page);
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
        Book tearBook(Book &b,int tearPage){
            int pagesNum = b.getpagesNum();
            if(tearPage > pagesNum){
                std::cout << "the page is not exist" << std::endl;
            }
            else{
                std::string wholeBook = b.getcontent();
                int word_a_page = b.getword_a_page();
                int start = word_a_page *(tearPage - 1);
                b.tearbook(start);
                return b;
            }
        }
};

int main(){
    BookWriter wa = BookWriter("123");
    BookReader rb = BookReader ("456");
    std::vector <Book *> book123;
    int isbn = 0;
    std::string bookname = "",content = "";
    std::cout << "Enter -1 to stop create book" << std::endl;
    while(1){
        std::cout << "ISBN:";
        std::cin >> isbn;
        if(isbn == -1){
            break;
        }
        std::cout << "Bookname:";
        std::cin >> bookname;
        std::cout << "content:";
        std::cin >> content;
        book123.push_back(new Book(wa.createBook(isbn,bookname,content)));
    }
    int booknumber = 0;
    std::string writecontent = "";
    std::cout << "Enter -1 to stop write book" << std::endl;
    while(1){
        std::cout << "The booknumber you want to write:";
        std::cin >> booknumber;
        if(booknumber == -1){
            break;
        }
        else if(booknumber >= book123.size()){
            std::cout << "The book is not exist" << std::endl;
            continue;
        }
        std::cout << "write content:";
        std::cin >> writecontent;
        wa.writeBook(*book123[booknumber],writecontent);
        std::cout << "Book number " << booknumber << " has been successfully written" << std::endl;
    }
    for(int i = 0;i < book123.size() ; i++){
        book123[i] -> showBook();
    }
    int readbooknumber = 0;
    int readpage = 0;
    std::cout << "Enter -1 to stop read book" << std::endl;
    while(1){
        std::cout << "The booknumber you want to read:";
        std::cin >> readbooknumber;
        if(readbooknumber == -1){
            break;
        }
        else if(readbooknumber >= book123.size()){
            std::cout << "The book is not exist" << std::endl;
            continue;
        }
        std::cout << "read page:";
        std::cin >> readpage;
        std::cout << rb.readBook(*book123[readbooknumber],readpage) << std::endl;
    }
    int tearbooknumber = 0,tearpage = 0;
    std::cout << "Enter -1 to stop tear book" << std::endl;
    while(1){
        std::cout << "The booknumber you want to tear:";
        std::cin >> tearbooknumber;
        if(tearbooknumber == -1){
            break;
        }
        else if(tearbooknumber >= book123.size()){
            std::cout << "The book is not exist" << std::endl;
            continue;
        }
        std::cout << "tear page:";
        std::cin >> tearpage;
        rb.tearBook(*book123[tearbooknumber],tearpage);
        std::cout << "The total pages of book number " << tearbooknumber << " is " << book123[tearbooknumber] -> getpagesNum() << std::endl;
    }
    for(int i = 0;i < book123.size() ; i++){
        book123[i] -> showBook();
    }
    for (Book* b : book123) {
        delete b;
    }
    book123.clear();
    return 0;
}