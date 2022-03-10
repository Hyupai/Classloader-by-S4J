-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Tempo de geração: 10/03/2022 às 18:58
-- Versão do servidor: 10.5.12-MariaDB-cll-lve
-- Versão do PHP: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `u634180599_server`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `clientes`
--

CREATE TABLE `clientes` (
  `Username` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Password` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `UID` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `devices` int(11) NOT NULL DEFAULT 1,
  `tempaeskey` varchar(16) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `clientes`
--

INSERT INTO `clientes` (`Username`, `Password`, `UID`, `devices`, `tempaeskey`) VALUES
('1', '1', '64335ac7597ce55356656626', 1, 'APUN1MIXMEUIP77N'),
('1234567890123456', '1234567890123456', '2e1d4b7c2769988358764788', 1, 'IYFUU75CJROKKUCU'),
('Hyupai', '1234', '2e1d4b7c2769988358764788', 1, 'XYBBIDO2APOM6RNO');

-- --------------------------------------------------------

--
-- Estrutura para tabela `tablename`
--

CREATE TABLE `tablename` (
  `ID` int(11) NOT NULL,
  `address` varchar(42) NOT NULL,
  `status` text DEFAULT NULL,
  `name` text NOT NULL,
  `nonce` tinytext DEFAULT NULL,
  `created` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Despejando dados para a tabela `tablename`
--

INSERT INTO `tablename` (`ID`, `address`, `status`, `name`, `nonce`, `created`) VALUES
(1, '0x3aa56776905735c450a5e1dfed8ddc702d3468f5', 'off', 'Eric', '621c1f7ba42f6', '2022-01-23 14:01:51'),
(2, '0x8a08bd63b78ed473ff981fb70cd9c3bb7653c1fd', 'off', 'Eric', '620edc9878868', '2022-01-23 14:02:41'),
(3, '0xfcb400cf82eb185d1501e1a698e140116d0e2966', 'off', 'Eric', '620edd3d2f50b', '2022-01-23 20:07:37'),
(4, '0xa957375c08be4a231c951695183b402285c2c2e3', 'off', 'Eric', '620edd0354758', '2022-01-25 14:38:46');

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`Username`);

--
-- Índices de tabela `tablename`
--
ALTER TABLE `tablename`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `address` (`address`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `tablename`
--
ALTER TABLE `tablename`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
