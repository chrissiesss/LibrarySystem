//
//  Created by Chriss on 2018/3/3.
//

#include "Library.h"

int main(int argc, const char * argv[])
{
    Reader *rhead,*rtail;
    Book *bhead,*btail;
    rhead = Reader_Initial(rtail);
    bhead = Book_Initial(btail);
    Maincourse(bhead, btail, rhead, rtail);
    return 0;
}
