/// 
/// Copyright (c) 2018 Zeutro, LLC. All rights reserved.

#ifndef __ZCONTEXTKPDPVS_H__
#define __ZCONTEXTKPDPVS_H__

///
/// @class  OpenABEContextKPDPVS
///
/// @brief  Implementation of the GPSW '06 KP-ABE encryption scheme.
///

using namespace oabe;

namespace oabe {

class OpenABEContextKPDPVS : public OpenABEContextABE {
public:
  // Constructors/destructors
  OpenABEContextKPDPVS(std::unique_ptr<OpenABERNG> rng);
  ~OpenABEContextKPDPVS();
  bool debug;

  // Main functions
  OpenABE_ERROR generateParams(OpenABESecurityLevel securityLevel,
                           const std::string &mpkID,
                           const std::string &mskID);

  OpenABE_ERROR generateParams(const std::string groupParams,
                           const std::string &mpkID,
                           const std::string &mskID);

  OpenABE_ERROR generateDecryptionKey(OpenABEFunctionInput *keyInput, const std::string &keyID,
                                  const std::string &mpkID, const std::string &mskID,
                                  const std::string &gpkID, const std::string &GID);

  OpenABE_ERROR encryptKEM(OpenABERNG *rng, const std::string &mpkID, const OpenABEFunctionInput *encryptInput,
                       uint32_t keyByteLen, const std::shared_ptr<OpenABESymKey>& key, OpenABECiphertext *ciphertext);

  OpenABE_ERROR decryptKEM(const std::string &mpkID, const std::string &keyID, OpenABECiphertext *ciphertext,
                       uint32_t keyByteLen, const std::shared_ptr<OpenABESymKey>& key);
};

}

#endif /* ifdef  __ZCONTEXTKPDPVS_H__ */
