package com.mina.factory;

public class Netmessage {
	
	private int id;
	
	private String content;
	
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}


	private short code;
	
	
	public void writeData(byte[] a,int size)
	{
		
	}
	public void writeDataPack(short size,short type,short code,int roleid) {
		
	}


	public void setCode(short code) {
		this.code = code;
	}


	public short getCode() {
		return code;
	}
}
