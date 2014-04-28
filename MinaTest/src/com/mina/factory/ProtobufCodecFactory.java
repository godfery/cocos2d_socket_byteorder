package com.mina.factory;

import org.apache.mina.core.session.IoSession;
import org.apache.mina.filter.codec.ProtocolCodecFactory;
import org.apache.mina.filter.codec.ProtocolDecoder;
import org.apache.mina.filter.codec.ProtocolEncoder;

public class ProtobufCodecFactory implements ProtocolCodecFactory  {
    private static final ProtobufEncoder ENCODER_INSTANCE = new ProtobufEncoder();
    private static final selfDecoder DECODER_INSTANCE = new selfDecoder();
                                                       
    public ProtobufCodecFactory() {
                                                           
    }
                                                       
    public selfDecoder getDecoder(IoSession session) throws Exception {
        return DECODER_INSTANCE;
    }
    public ProtocolEncoder getEncoder(IoSession session) throws Exception {
        return ENCODER_INSTANCE;
    }
                                                       
}