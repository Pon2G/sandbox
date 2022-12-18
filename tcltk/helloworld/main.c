/*
 * These codes are licensed under CC0.
 * http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
#include <tcl.h>
#include <tk.h>

//独自コマンドの作成
int proc(ClientData clientData, Tcl_Interp* interp, int argc, const char* argv[])
{
    //argc:引数の数
    //argv[0]:自分自身(コマンド名)
    //argv[1]～:引数

    if ( argc != 1 )
    {
        char *retmsg = "argument error";
        Tcl_SetResult(interp, retmsg, TCL_VOLATILE);
        return TCL_ERROR;
    }
    printf("Call!\n");

    char *retvalue = "0";
    Tcl_SetResult(interp, retvalue, TCL_VOLATILE);
    return TCL_OK;

    //終了コードの種類
    //TCL_OK、TCL_ERROR、 TCL_RETURN、TCL_BREAK、またはTCL_CONTINUE

    //応答の種類
    //TCL_STATIC ... データが静的な領域(static char)にあって、関数を抜けてもその領域が上書きされない場合
    //TCL_VOLATILE ... データが揮発する(auto char)スタック領域にあり、関数を抜けると上書きされる場合
    //TCL_DYNAMIC ... データがAPI Tcl_Allocで確保された領域にある場合
}

int main(int argc, char* argv[])
{
    Tcl_Interp *interp = Tcl_CreateInterp(); //インタプリタを作成
    Tcl_FindExecutable(argv[0]); //初期化前準備
    if ( Tcl_Init(interp) == TCL_ERROR ) //Tclを初期化(スタンダートライブラリinit.tclをロード)
    {
        const char *errmsg = Tcl_GetStringResult(interp); //エラーメッセージの取得
        printf("インタプリタの初期化に失敗: %s\n",errmsg);
        return -1;
    }
    if ( Tk_Init(interp) == TCL_ERROR ) //Tkを初期化(GUIライブラリをロード)
    {
        const char *errmsg = Tcl_GetStringResult(interp); //エラーメッセージの取得
        printf("GUIライブラリの初期化に失敗: %s\n", errmsg);
        return -1;
    }

    //コマンドを作る
    Tcl_CreateCommand(interp,"testproc",proc,NULL,NULL);

    if ( Tcl_EvalFile(interp, "script.tcl") == TCL_ERROR )//インタプリタで実行
    {
        const char *errmsg = Tcl_GetStringResult(interp); //エラーメッセージの取得
        printf("実行失敗: エラー内容:%s\n", errmsg);
        return -1;
    }else{
        const char *errmsg = Tcl_GetStringResult(interp); //エラーメッセージの取得
        printf("実行成功:%s\n", errmsg);
    }

    Tk_MainLoop();//Tkのイベントループへ

    Tcl_DeleteInterp(interp); //インタプリタのお片付け
    return 0;
}
