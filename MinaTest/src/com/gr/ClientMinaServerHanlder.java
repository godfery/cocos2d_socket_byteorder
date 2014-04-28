package com.gr;

import org.apache.mina.core.service.IoHandlerAdapter;
import org.apache.mina.core.session.IdleStatus;
import org.apache.mina.core.session.IoSession;

import com.mina.factory.Netmessage;
import com.object.HimiObject;
 
public class ClientMinaServerHanlder extends IoHandlerAdapter {
 
    private int count = 0;
 
    // 当一个新客户端连接后触发此方法.
    public void sessionCreated(IoSession session) {
        System.out.println("新客户端连接");
    }
 
    // 当一个客端端连结进入时 @Override
    public void sessionOpened(IoSession session) throws Exception {
        count++;
        System.out.println("第 " + count + " 个 client 登陆！address： : "
                + session.getRemoteAddress());
 
    }
 
    // 当客户端发送的消息到达时:
    @Override
    public void messageReceived(IoSession session, Object message)
            throws Exception {
        // // 我们己设定了服务器解析消息的规则是一行一行读取,这里就可转为String:
//         String s = (String) message;
//         // Write the received data back to remote peer
//         System.out.println("收到客户机发来的消息: " + s);
//         // 测试将消息回送给客户端 session.write(s+count); count++;
//         session.write(s);
//        HimiObject ho = (HimiObject) message;
//        System.out.println(ho.getName());
// 
//        ho.setName("serverHimi");
//        session.write(ho);
    	  Netmessage nm = (Netmessage)message;
    	  System.out.println("ClientMinaHandle");
    	  System.out.println(nm.getId());
    	  System.out.println(nm.getContent());
    	  
    	  session.write(nm);
    }
 
    // 当信息已经传送给客户端后触发此方法.
    @Override
    public void messageSent(IoSession session, Object message) {
        System.out.println("信息已经传送给客户端");
 
    }
 
    // 当一个客户端关闭时
    @Override
    public void sessionClosed(IoSession session) {
        System.out.println("one Clinet Disconnect !");
    }
 
    // 当连接空闲时触发此方法.
    @Override
    public void sessionIdle(IoSession session, IdleStatus status) {
        System.out.println("连接空闲");
    }
 
    // 当接口中其他方法抛出异常未被捕获时触发此方法
    @Override
    public void exceptionCaught(IoSession session, Throwable cause) {
    	System.out.println(cause.toString());
        System.out.println(cause.getCause());
    	System.out.println("其他方法抛出异常");
    }
 
}
