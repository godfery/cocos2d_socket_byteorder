package com.mina.factory;

import org.apache.log4j.Logger;
import org.apache.mina.core.buffer.IoBuffer;
import org.apache.mina.core.session.IoSession;
import org.apache.mina.filter.codec.CumulativeProtocolDecoder;
import org.apache.mina.filter.codec.ProtocolDecoderOutput;


public class ProtobufDecoder extends CumulativeProtocolDecoder {
    private static final Logger log = Logger.getLogger(ProtobufDecoder.class);
                      
    protected ProtobufDecoder() {
    }
                      
    /**
     * 把二进制流解码为服务器使用的数据包格式
     */
    @Override
    protected boolean doDecode(IoSession session, IoBuffer in, ProtocolDecoderOutput out) throws Exception {
//      private short size;//包大小
//      private short type;//版本号
//      private short code;//包类型
//      private int roleid; // 玩家ID
        IoBuffer newBuf = in.slice();
        //size
        int size = newBuf.getShort();
                          
        System.out.printf("c size = %d\n",size);
                          
        if (size <= 0 || size >= Short.MAX_VALUE) {
            // 非法的数据长度
            log.debug("Message Length Invalid size = " + size + ", throw this Message.");
            return true;
        }
        System.out.print(newBuf.getHexDump());
                          
        //000A 0001 0001 0000 0001
        System.out.printf("buffer size = %d",in.remaining());
        if (size > in.remaining()) {
            // 数据还不够读取,等待下一次读取
            System.out.printf("Data not integrity. there is a lack of " + (size - newBuf.remaining()) + " bytes.");
            return true;
        }
        Netmessage res=new Netmessage();
        short type=newBuf.getShort();
        short code=newBuf.getShort();
        int roleid=newBuf.getInt();
        //int roleid=newBuf.getInt();
        System.out.printf("type =  %d code = %d roleid = %d\n",(int)type,(int)code,roleid);
        res.writeDataPack((short)size, type, code, roleid);
                         
        // BODY
        int bodyLen = size-10;
        if (bodyLen > 0) {
            byte[] bytes = new byte[bodyLen];
            in.get(bytes, 0, bodyLen);
            res.writeData(bytes,size);
        }
        out.write(res);
        return false;
    }
}
