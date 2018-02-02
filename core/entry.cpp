

#include "entry.h"
#include "hash.h"

#include <glog/logging.h>

CEntry::CEntry() {

    SetNull();

}


uint256 CEntry::GetEntryHash() const {

    return SerializeHash (*this);

}


bool CEntry::IsBaseSign() const {

    return m_sender.IsEmpty() && m_sign.EmptySignature();

}


bool CEntry::Signature(const CKey &key) {

    return m_sign.Sinature(key, m_sender, GetEntryHash());

}


bool CEntry::VerifySign() const {

    return m_sign.VerifySign (m_sender, GetEntryHash());
    
}


bool CEntry::Check() const {

    if (not m_receiver.IsValid()) {
	LOG(ERROR) << "reciver is invalid";
	return false;
    }

    if ( m_value > MAX_TRAN_LKT) {
	LOG(ERROR) << "value is invalid, value: "<< m_value;
	return false;
    }

    if (not IsBaseSign()) {
	if (m_fee > MAX_LKC_FEE || m_fee < MIN_LKC_FEE) {
	    LOG(ERROR) << "fee is invalid";
	    return false;
	}
    }

    if (not IsBaseSign()) {

	if (not VerifySign()) {
	    LOG(ERROR) << "verify sign failed ...";
	    return false;

	}

    }

    return true;
}



void CEntry::SetNull() {

    m_type = m_createTime = 0;

    m_value = m_fee = 0;
     
}


CEntryDB::CEntryDB() {

    

}


string CEntry::ToJsonString () const {

    std::stringstream ss;

    ss << "{ \"type\": " << GetType() << ", \"createTime\":"
       << GetCreateTime() << ", \"sender\": \"" << GetSender().ToString()
       << "\", \"receiver\":\"" << GetReceiver().ToString()
       << "\", \"sign\":\"" << GetSign().ToString() << "\",\"value\":"
       << GetValue() << ", \"fee\":" << GetFee() << "}";


    return ss.str();

}


string CEntry::GetJsonFromEntrys (const std::vector<CEntry>& entrys) {

    std::stringstream ss;

    ss << "[ ";

    for (size_t i = 0; i < entrys.size(); ++i) {

	const CEntry& cen = entrys[i];

	ss << cen.ToJsonString() << ",";
	
    }

    string res = ss.str();

    res = res.substr(0, res.length() - 1);

    res += "]";

    return res;
    
}