package com.mina.factory;

import java.io.UnsupportedEncodingException;

import org.apache.log4j.Logger;
import org.apache.mina.core.buffer.IoBuffer;
import org.apache.mina.core.session.IoSession;
import org.apache.mina.filter.codec.CumulativeProtocolDecoder;
import org.apache.mina.filter.codec.ProtocolDecoderOutput;

public class selfDecoder extends CumulativeProtocolDecoder {
	private static final Logger log = Logger.getLogger(selfDecoder.class);

	protected selfDecoder() {
	}

	/**
	 * 把二进制流解码为服务器使用的数据包格式
	 */
	@Override
	protected boolean doDecode(IoSession session, IoBuffer in,
			ProtocolDecoderOutput out) throws Exception {
		// private short size;//包大小
		// private short type;//版本号
		// private short code;//包类型
		// private int roleid; // 玩家ID
		IoBuffer newBuf = in.slice();
		// size
		System.out.println(newBuf);
		int size = newBuf.getInt();
		System.out.printf("c size = %d\n", size);
		int length = newBuf.getInt();
		System.out.printf("c size = %d\n", length);
		byte[] bytesaa = new byte[length];
		newBuf.get(bytesaa);
		String as = null;
		try {
			as = new String(bytesaa, "UTF-8");
		} catch (UnsupportedEncodingException e) {
		}

		System.out.println(as);
		Netmessage res = new Netmessage();
		res.setId(size);
		res.setContent(as);
		out.write(res);
		return false;
		// if (size <= 0 || size >= Short.MAX_VALUE) {
		// // 非法的数据长度
		// log.debug("Message Length Invalid size = " + size +
		// ", throw this Message.");
		// return true;
		// }

	}
}
