import imaplib, email.parser, email.header, os, os.path

SERVER_NAME='imap.gmail.com'
USERNAME='masataka.shibata.sss@gmail.com'
PASSWORD='Sativa5466'

MBOX='INBOX'

JSN_DIR = './jsn'

'''
mimeエンコードされたheaderをデコードしstr文字列を返します。
'''

def decode_mime_header(s0):
    '''decode a mime encoded header to get a string'''
    return ''.join( str(s, c or 'ascii') if isinstance(s, (bytes,)) else s  for s,c in email.header.decode_header(s0) )


'''
引数「obj」メールオブジェクトの添付ファイル有無を判定します。
'''
def is_attachment(obj):
    '''see if obj is an attachment'''
    s=obj['Content-Disposition']
    return s and s.startswith('attachment')

'''
get_jsn_each()はget_jsn()から呼び出され、引数「e」メールオブジェクトの添付ファイル(json)を
引数「d_jsn」で指定されたディレクトリに保存します。

'''
def get_jsn_each(d_jsn, e):
    '''save attachments of a Message Object (e) in d_jsn'''
    if e.is_multipart():
        for p in e.walk():
            if (not p.is_multipart()) and is_attachment(p) and p.get_content_maintype() =='application':
                fname0 = p.get_filename()
                if fname0:
                    fname=decode_mime_header(fname0)
                    try:
                        with open(os.path.join(d_jsn, fname), 'wb' ) as f:
                            f.write(p.get_payload(None, True))
                    except:
                        print('cannot save ' + fname)
                    print(fname)
                else:
                    print('cannot get filename')
'''
get_jsn()はメールボックスのすべてのメールオブジェクトの添付ファイルを保存します。
'UNSEEN'を指定すると未読メールオブジェクトの添付ファイルを保存します。
'''
def get_jsn(con, mbox, d_jsn):
    '''save attachments of all emails in mbox'''
    con.select(mbox)
    p=email.parser.BytesParser()
    _type, _data = con.search(None,  'ALL')
    #_type, _data = con.search(None,  'UNSEEN')

    for num in _data[0].split():
        type, data = con.fetch(num, '(RFC822)')
        get_jsn_each(d_jsn, p.parsebytes(data[0][1]))

if __name__=='__main__':

    if not os.path.isdir(JSN_DIR):
        os.mkdir(JSN_DIR)

    con = imaplib.IMAP4_SSL(SERVER_NAME)
    con.login(USERNAME, PASSWORD)

    get_jsn(con, MBOX, JSN_DIR)
    con.close()
    con.logout()
