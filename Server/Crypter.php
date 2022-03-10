<?php
//api url filter
if(strpos($_SERVER['REQUEST_URI'],"Crypter.php")){
    require_once 'Utils.php';
    PlainDie();
}

require "Crypt/RSA.php";

class Crypter {
    private $rsa;

    function __construct(){
        $this->rsa = new Crypt_RSA();
        $this->rsa->setEncryptionMode(CRYPT_RSA_ENCRYPTION_PKCS1);
        $this->rsa->setPrivateKeyFormat(CRYPT_RSA_PRIVATE_FORMAT_PKCS8);
        $this->rsa->setPublicKeyFormat(CRYPT_RSA_PUBLIC_FORMAT_PKCS8);
        $this->rsa->setSignatureMode(CRYPT_RSA_SIGNATURE_PKCS1);
        $this->rsa->setHash('sha256');
        $this->genNewKey();
    }

    public static function init(){
        return new Crypter();
    }

    public function loadKey($key, $type = false){
        $this->rsa->loadKey($key, $type);
    }

    public function genNewKey(){
        $newkey = $this->rsa->createKey();
        $this->loadKey($newkey["privatekey"],CRYPT_RSA_PRIVATE_FORMAT_PKCS8);
        return $newkey;
    }

    public function encryptByPublic($publickey, $plaintext){
        $this->loadKey($publickey);
        return $this->rsa->encrypt($plaintext);
    }

    public function decryptByPublic($publickey, $ciphertext){
        $this->loadKey($publickey);
        return $this->rsa->decrypt($ciphertext);
    }

    public function encryptByPrivate($privatekey, $plaintext){
        $this->loadKey($privatekey);
        return $this->rsa->encrypt($plaintext);
    }

    public function decryptByPrivate($privatekey, $ciphertext){
        $this->loadKey($privatekey);
        return $this->rsa->decrypt($ciphertext);
    }

    public function signByPrivate($privatekey, $plaintext){
        $this->loadKey($privatekey);
        return $this->rsa->sign($plaintext);
    }

    public function verifyByPublic($publickey, $plaintext, $signature){
        $this->loadKey($publickey);
        return $this->rsa->verify($plaintext, $signature);
    }

    public function getPublicKey(){
        return $this->rsa->getPublicKey();
    }

    public function getPrivateKey(){
        return $this->rsa->getPrivateKey();
    }

    public function getPublicKeyBinary(){
        $publickey = $this->getPublicKey();
        $publickey = str_replace("-----BEGIN PUBLIC KEY-----","", $publickey);
        $publickey = str_replace("-----END PUBLIC KEY-----","", $publickey);
        $publickey = trim($publickey);
        return fromBase64($publickey);
    }

    public function getPrivateKeyBinary(){
        $privatekey = $this->getPrivateKey();
        $privatekey = str_replace("-----BEGIN PRIVATE KEY-----","", $privatekey);
        $privatekey = str_replace("-----END PRIVATE KEY-----","", $privatekey);
        $privatekey = trim($privatekey);
        return fromBase64($privatekey);
    }
}